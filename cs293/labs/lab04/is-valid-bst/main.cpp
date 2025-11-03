#include "is-valid-bst.h"
#include "employee.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

namespace test_code 
{
    std::vector<std::shared_ptr<struct node_t<struct employee_t>>>
    read_employee_tree_level(std::string &line) 
    {
        std::vector<std::shared_ptr<struct node_t<struct employee_t>>> level;
        std::istringstream iss(line);
        std::string token;
        
        while (std::getline(iss, token, ' ')) 
        {
            if (token.empty()) continue;

            if (token == "null") 
            {
                level.push_back(nullptr);
                continue;
            } 
            
            std::istringstream token_iss(token);
            std::string name, department_name, id_in_department, job_title, salary;
            
            std::getline(token_iss, name, ',');
            std::getline(token_iss, department_name, ',');
            std::getline(token_iss, id_in_department, ',');
            std::getline(token_iss, job_title, ',');
            std::getline(token_iss, salary, ',');
            
            level.push_back(std::make_shared<struct node_t<struct employee_t>>(
                employee_t{name, department_name, std::stol(id_in_department), 
                           job_title, std::stod(salary)}));
        }
        return level;
    }

    std::vector<std::shared_ptr<struct node_t<struct employee_t>>> 
    update_next_level(std::string &line, std::vector<std::shared_ptr<struct node_t<struct employee_t>>> &this_level) 
    {
        std::vector<std::shared_ptr<struct node_t<struct employee_t>>> next_level;
        int index = 0;
        for (auto node : read_employee_tree_level(line)) 
        {
            if (!node) 
            {
                index++;
                continue;
            }
            if (index % 2 == 0) 
            {
                this_level[index / 2]->left_child = node;
                node->parent = this_level[index / 2];
            } 
            else 
            {
                this_level[index / 2]->right_child = node;
                node->parent = this_level[index / 2];
            }
            
            next_level.push_back(node);
            index++;
        }
        return next_level;
    }

    std::shared_ptr<struct node_t<struct employee_t>> 
    read_employee_tree_from_stdin() 
    {
        std::shared_ptr<struct node_t<struct employee_t>> root;
        std::vector<std::shared_ptr<struct node_t<struct employee_t>>> this_level;
        std::string line;
        
        if (!std::getline(std::cin, line)) 
        {
            return nullptr; // empty input
        }

        this_level = read_employee_tree_level(line);
        if (this_level.empty()) return nullptr;

        root = this_level[0];
        
        while (std::getline(std::cin, line)) 
        {
            this_level = update_next_level(line, this_level);
        }
        
        return root;
    }
} // namespace test_code

int main(int argc, char** argv){
    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == nullptr) // cin redirects to file argv[1]
        {
            std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
            return 1;
        }
    }
    auto root = test_code::read_employee_tree_from_stdin();
    bool result = is_valid_bst(root);
    std::cout << std::boolalpha << result << std::endl;
    return 0;
}
