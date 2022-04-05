#include "include/grammar.hh"
#include "include/json.hpp"

string Grammar::parse(string filename)
{
    ifstream file("../" + filename);
    nlohmann::json grammar;
    file >> grammar;

    angle_ = grammar["angle"];
    steps_ = grammar["steps"];
    expanded_ = grammar["axiom"];

    map<char, vector<string>> rules;
    for (auto& [key, val] : grammar["rules"].items()) // map each rule to its expansion
    {
        char init = key[0];
        if (rules.find(init) == rules.end())
            rules[init] = vector<string>();

        rules[init].push_back(val);
    }

    for (int step = 0; step < steps_; step++)
    {
        string expanded;
        for (char c : expanded_)
        {
            // if this rule exists, expand it
            auto found = rules.find(c);
            if (found != rules.end())
            {
                vector<string> opts = (*found).second;
                expanded.append(opts[rand() % opts.size()]);
                continue;
            }

            // not a rule, just push it
            expanded.push_back(c);
        }
        expanded_ = expanded;
    }
    
    return expanded_;
}

float Grammar::getAngle()
{
    return angle_;
}