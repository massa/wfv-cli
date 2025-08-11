
#include <span>
#include <ranges>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string_view>

#include "pe_bliss.h"
#include "pe_bliss_resources.h"

using namespace pe_bliss;

auto windows_file_version(std::string_view f) -> std::string {
    try {
        std::ifstream input { f.data(), std::ios::in | std::ios::binary };
        pe_base b { pe_factory::create_pe(input) };
        const resource_directory dir { get_resources(b) };
        pe_resource_viewer v { dir };
        lang_string_values_map strings;
        translation_values_map translations;
        file_version_info i { resource_version_info_reader(v).get_version_info(strings, translations) };
        return i.get_file_version_string<char>();
    } catch(...) {
        return {};
    }
}

int main(int argc, char **argv) {
    if( argc == 2 ) {
        std::cout << windows_file_version(argv[1]) << '\n';
        return 0;
    }
    for( std::string_view a: std::span { argv+1, argv+argc } ) {
        std::cout << windows_file_version(a) << '\t' << a << '\n';
    }
}

