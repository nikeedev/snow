module snow

import os
import strconv

fn find(array []string, element string) int {
	mut j := 0

	if typeof(strconv.atoi(element)).name == 'int' {
		j = 5
	}
	mut done := false
	for i := 0; i < array.len; i++ {
		if array[i] == element {
			j = i
			done = true
		}
	}
	if done == false {
		j = 6
	}


	return j
}

enum TokenTypes {
	plus = 0
	minus
	multi
	div
	equals
	number
	identifier
}

const (
	token_type_string = [
		'+',
		'-',
		'*',
		'/',
		'='
	]
)

struct Token {
mut:
	value string
	token_type TokenTypes
}

fn token(value string, token_type TokenTypes) Token {
	return Token{ value: value, token_type: token_type }
}


pub fn load(file string) ! {
	mut tokens := []Token{}

	mut f := os.read_lines(file) or { panic(err) }

	mut src_raw := ""
	for line in f {
		src_raw += line.str().trim_space()
	}

	// println(src_raw)

	mut src := src_raw.split(' ')

	for line in src {
		if line.trim_space() == " " {
			src.delete(src.index(line))
		}
		if line.trim_space().starts_with("//") {
			src.delete(src.index(line))
		}
	}

	for line in src {
		if line == '5' {
			println(find(token_type_string, line))
		}
		if find(token_type_string, line) == int(TokenTypes.plus)
		{
			tokens << token(line, .plus)
		}
		else if find(token_type_string, line) == int(TokenTypes.minus)
		{
			tokens << token(line, .minus)
		}
		else if find(token_type_string, line) == int(TokenTypes.multi)
		{
			tokens << token(line, .multi)
		}
		else if find(token_type_string, line) == int(TokenTypes.div)
		{
			tokens << token(line, .div)
		}
		else if find(token_type_string, line) == int(TokenTypes.equals)
		{
			tokens << token(line, .equals)
		}
		else if find(token_type_string, line) == int(TokenTypes.number)
		{
			tokens << token(strconv.atoi(line)!, .number)
		}
		else
		{
			tokens << token(line, .identifier)
		}
	}

	for token in tokens {
		println(token)
	}

	// for line in code {
	// 	println(line)
	// }


}
