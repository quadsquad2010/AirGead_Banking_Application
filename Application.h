#ifndef APPLICATION_H
#define APPLICATION_H

// Application Class Definition
class Application {
public:
    void Run();

private:
    double PromptPositiveDouble(const char* promptText);
    int PromptPositiveInt(const char* promptText);
};

#endif