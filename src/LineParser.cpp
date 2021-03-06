/*
 * Created by Nicolas Fez for RemoteControl.
 * Started on 24/10/2018.
 */

#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include "LineParser.hh"

LineParser::LineParser()
{
    this->setLine("");
    this->setWords(std::vector<std::string>());
}

LineParser::LineParser(LineParser const &other)
{
    this->setLine(other.getLine());
    this->setWords(other.getWords());
}

LineParser::~LineParser()
{
}

LineParser &LineParser::operator=(LineParser const &other)
{
    if (this != &other)
    {
        this->setLine(other.getLine());
        this->setWords(other.getWords());
    }
    return *this;
}

void LineParser::getUserEntry()
{
    std::getline(std::cin, this->line);
    std::stringstream stream(this->getLine());
    std::string word;

    this->words.clear();
    while (stream >> word)
    {
        this->words.push_back(word);
    }
}

std::string const &LineParser::getLine() const
{
    return this->line;
}

void LineParser::setLine(std::string const &line)
{
    this->line = line;
}

std::vector<std::string> const &LineParser::getWords() const
{
    return this->words;
}

void LineParser::setWords(std::vector<std::string> const &words)
{
    this->words = words;
}