module snow_lib

import os

enum TokenTypes {
	number
	equals
	plus
	minus
	multiply
	divide
	open_paran
	closed_paran
}

struct Token {
mut:
	value string
	token_type TokenTypes
}

fn token(value string, token_type TokenTypes) Token {
	return Token{ value: value, token_type: token_type }
}


pub fn load(file string) {
	mut tokens := []Token{}

	mut f := os.read_lines(file) or { panic(err) }

	mut src_raw := ""
	for line in f {
		src_raw += line.str()
	}
	mut src_arr := src_raw.split("\n")[0].split(" ")
	println(src_arr)

	for i := 0; i < src_arr.len; i++ {
		src_arr[i] = src_arr[i].trim_space()

	}

	println(src_raw)

	/*
	mut i := 0
	for line in src {
		for i < line.len {
			match line[i].ascii_str() {
				'+' {
					tokens << Token{ value: "+", token_type: .plus }
				}
				'-' {
					tokens << Token{ value: "-", token_type: .minus }
				}
				'*' {
					tokens << Token{ value: "*", token_type: .multiply }
				}
				'/' {
					tokens << Token{ value: "/", token_type: .divide }
				}
				else {
					tokens << Token{ value: line[i].ascii_str(), token_type: .number }
				}
			}
			i++
		}
		i = 0
	}
	*/
	for token in tokens {
		println(token)
	}

	// for line in code {
	// 	println(line)
	// }


}
