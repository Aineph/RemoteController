/*
 * Created by Nicolas Fez for RemoteControl.
 * Started on 24/10/2018.
 */

#ifndef REMOTECONTROL_LINEPARSER_HH
#define REMOTECONTROL_LINEPARSER_HH

class LineParser
{
private:
    std::string line;
    std::vector<std::string> words;

public:
    LineParser();

    LineParser(LineParser const &other);

    virtual ~LineParser();

    LineParser &operator=(LineParser const &other);

    void getUserEntry();

    std::string const& getLine() const;

    void setLine(std::string const& line);

    std::vector<std::string> const& getWords() const;

    void setWords(std::vector<std::string> const& words);

};


#endif //REMOTECONTROL_LINEPARSER_HH
