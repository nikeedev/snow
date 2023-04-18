#include "snow.h"

void load(const std::string& file)
{
    std::ifstream code;

	code.open(file);

    if (!code) {
        std::cout << "Error! '" << file << "' doesn\'t exist" << std::endl;
        exit(-1);
    }

    for (int i = 0; i < code.get(); i++)
    {
        /* code */
    }


    code.close();
}
