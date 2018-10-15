  #include <iostream>
    #include <vector>
    #include <boost/filesystem.hpp>

    namespace fs = boost::filesystem;
	
    int main(int ac, char** av)
    {
		std::string path;
		std::vector<std::string> namelist;
		
        fs::path p("./src");
        fs::recursive_directory_iterator begin(p), end;
        std::vector<fs::directory_entry> v(begin, end);

        for(auto& f: v) {
			path = f.path().string();
			if (path.find(".java") != std::string::npos) {
				std::string extractfile = path.substr(path.find_last_of("/")+1, path.find_last_of("."));
				std::string extractname = extractfile.substr(0, extractfile.find_last_of("."));
				namelist.push_back(extractname);
			}
		}
		
		std::sort(namelist.begin(), namelist.end());
		
		for (auto &i : namelist)
			std::cout << i << std::endl;
		
    }