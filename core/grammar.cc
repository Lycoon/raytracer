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

    map<char, string> rules;
    for (auto rule : grammar["rules"]) // map each rule to its expansion
    {
        string init = rule["init"];
        rules[init[0]] = rule["rule"];
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
                expanded.append((*found).second);
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