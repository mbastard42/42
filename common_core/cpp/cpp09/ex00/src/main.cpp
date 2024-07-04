# include <map>
# include <utility>
# include <fstream>
# include <sstream>
# include <iostream>

int is_date(std::string date) {

    std::string tmp;
    std::stringstream ssline(date);
    for(int i = 0; i < 3; i++) {
        std::getline(ssline, tmp, '-');
        if (i == 1 && (std::stoi(tmp) > 12 || std::stoi(tmp) < 1))
            return 0;
        if (i == 2 && (std::stoi(tmp) > 31 || std::stoi(tmp) < 1))
            return 0;
    }
    return 1;
}

std::string new_key(std::string oldkey) {
    
    std::string key;
    int intdate[3];
    std::string date[3];
    std::stringstream ssline(oldkey);

    for(int i = 0; i < 3; i++) {
        std::getline(ssline, date[i], '-');
        intdate[i] = std::stoi(date[i]);
    }
    if (intdate[2] == 1) {
        intdate[2] = 31;
        if (intdate[1] == 1) {
            intdate[1] = 12;
            intdate[0]--;
        } else {intdate[1]--;}
    } else {intdate[2]--;}
    for(int i = 0; i < 3; i++) {
        if (intdate[i] < 9)
            key += "0";
        key += std::to_string(intdate[i]);
        if (i < 2)
            key += "-";
    }
    return key;
}

std::string nearest_key(std::map<std::string, double> data, std::string oldkey) {

    std::string key; 
    try {
        data.at(oldkey);
        return oldkey;
    }
    catch (std::exception e) {
        return nearest_key(data, new_key(oldkey));
    }
}

int main(int ac, char **av) {

	std::fstream data_stream;
	std::fstream file_stream;
    std::map<std::string, double> data;
    std::map<std::string, double> file;

    if (ac == 2) {
        data_stream.open("data.csv");
        if (data_stream.good()) {
            file_stream.open(av[1]);
            if (file_stream.good()) {
                int count = 2;
                std::string line;

                std::getline(data_stream, line, '\n');
                while (std::getline(data_stream, line, '\n'))
                {
                    std::string key;
                    double value;

                    std::stringstream ssline(line);
                    std::getline(ssline, key, ',');

                    ssline >> value;
                    data[key] = value;
                }

                std::getline(file_stream, line, '\n');
                while (std::getline(file_stream, line, '\n'))
                {
                    if (line.find('|') != std::string::npos && is_date(line)) {

                        std::string key;
                        std::string trash;
                        double value;

                        std::stringstream ssline(line);
                        std::getline(ssline, key, ' ');
                        std::getline(ssline, trash, ' ');

                        ssline >> value;
                        if (value > 0 && value < 1000) {
                            double tmp = value * data[nearest_key(data, key)];
                            std::cout << key << " => " << value << " = " << tmp << std::endl;
                        }
                        else {std::cout << "Error at line " << count << ": bad number => " << line << std::endl;}
                    }
                    else {std::cout << "Error at line " << count << ": bad input => " << line << std::endl;}
                    count++;
                }
            }
            else {std::cout << "Can't open file" << std::endl;}
            file_stream.close();
        }
        else {std::cout << "Can't open database" << std::endl;}
        data_stream.close();
    }
    else {std::cout << "Wrong number of argument" << std::endl;}
    return 0;
}