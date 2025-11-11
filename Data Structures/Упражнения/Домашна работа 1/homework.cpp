
#include <iostream>
#include <cstdio>
#include <cctype>
#include <ctime>
using namespace std;


class MyString {
    class Node {
    public:
        char c;
        Node* next;
        explicit Node(const char ch) : c(ch), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int len;

    void freeList() {
        const Node* cur = head;
        while (cur) { const Node* nxt = cur->next; delete cur; cur = nxt; }
        head = tail = nullptr;
        len = 0;
    }
    void copyFrom(const MyString& other) {
        const Node* cur = other.head;
        while (cur) { append(cur->c); cur = cur->next; }
    }

public:
    MyString(): head(nullptr), tail(nullptr), len(0) {}
    MyString(const MyString& o): head(nullptr), tail(nullptr), len(0) { copyFrom(o); }
    MyString& operator=(const MyString& o){
        if (this != &o){ freeList(); copyFrom(o); }
        return *this;
    }
    ~MyString(){ freeList(); }

    void append(const char ch){
        Node* n = new Node(ch);
        if (!head){ head = tail = n; }
        else { tail->next = n; tail = n; }
        ++len;
    }
    int length() const { return len; }
    bool isEmpty() const { return len == 0; }

    void toLowerInPlace() const {
        for (Node* cur = head; cur; cur = cur->next){
             const char ch = ( char)cur->c;
            cur->c = static_cast<char>(tolower(ch));
        }
    }

    bool containsChar(const char ch) const {
        for (const Node* cur = head; cur; cur = cur->next) if (cur->c == ch) return true;
        return false;
    }

    template<typename F>
    void forEach(F fn) const { for (Node* cur = head; cur; cur = cur->next) fn(cur->c); }

    void printRaw() const { forEach([](const char c){ std::cout << c; }); }

    void printMasked(const class CharSet& guesses) const;
    bool allRevealed(const class CharSet& guesses) const;
    void printWord() const { printRaw(); }
};


class CharSet {
    class Node {
    public:
        char c;
        Node* next;
        explicit Node(const  char ch): c(ch), next(nullptr) {}
    };
    Node* head;

public:
    CharSet(): head(nullptr) {}
    ~CharSet(){
        const Node* cur = head;
        while (cur){ const Node* nxt = cur->next; delete cur; cur = nxt; }
    }

    bool contains(const char ch) const {
        for (const Node* cur = head; cur; cur = cur->next) if (cur->c == ch) return true;
        return false;
    }
    void add(const char ch){
        if (contains(ch)) return;
        Node* n = new Node(ch);
        n->next = head;
        head = n;
    }
    void printSortedLike() const {
        for (char a = 'a'; a <= 'z'; ++a) if (contains(a)) cout << a << ' ';
    }
};

void MyString::printMasked(const CharSet& guesses) const {
    forEach([&](const char c){
        if (!isalpha(c)) {cout << c; }
        else if (guesses.contains(c)) { cout << c; }
        else { cout << '_'; }
    });
}

bool MyString::allRevealed(const CharSet& guesses) const {
    bool ok = true;
    forEach([&](char c){ if (std::isalpha(( char)c) && !guesses.contains(c)) ok = false; });
    return ok;
}


class WordList {
private:
    class Node {
    public:
        MyString word;
        Node* next;
        explicit Node(const MyString& w): word(w), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int sz;

public:
    WordList(): head(nullptr), tail(nullptr), sz(0) {}
    ~WordList(){
        const Node* cur = head;
        while (cur){ const Node* nxt = cur->next; delete cur; cur = nxt; }
    }

    void pushBack(const MyString& w){
        Node* n = new Node(w);
        if (!head){ head = tail = n; }
        else { tail->next = n; tail = n; }
        ++sz;
    }
    int size() const { return sz; }

    MyString* getAt(int index) const {
        if (index < 0 || index >= sz) return nullptr;
       Node* cur = head;
        while (index-- > 0 && cur) cur = cur->next;
        return cur ? &cur->word : nullptr;
    }
};


static void drawHangman(const int wrong){

    cout << " |   |\n";
    cout << " " << (wrong >= 1 ? 'O' : ' ') << "   |\n";
    cout << (wrong >= 3 ? '/' : ' ') << (wrong >= 2 ? '|' : ' ') << (wrong >= 4 ? '\\' : ' ') << "  |\n";
    cout << (wrong >= 5 ? '/' : ' ') << " " << (wrong >= 6 ? '\\' : ' ') << "  |\n";

}

static bool isLetter(const char ch){
    return std::isalpha(static_cast<unsigned char>(ch)) != 0;
}
static char toLowerChar(const char ch){
    return static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
}

static bool loadWords(const char* path, WordList& list){
    FILE* f = std::fopen(path, "r");
    if (!f) return false;

    MyString current;
    int r;
    bool any = false;

    while ((r = std::fgetc(f)) != -1){
        const char ch = static_cast<char>(r);
        if (ch == '\r') continue;
        if (ch == '\n'){
            if (!current.isEmpty()){
                current.toLowerInPlace();
                list.pushBack(current);
                current = MyString();
                any = true;
            }
        } else {
            current.append(ch);
        }
    }
    if (!current.isEmpty()){
        current.toLowerInPlace();
        list.pushBack(current);
        any = true;
    }
    std::fclose(f);
    return any;
}


int main(){
    cout << "Hangman \n";
    cout << "Loading words from words.txt ...\n";

    WordList words;
    if (!loadWords("words.txt", words)){
        cout << "Error: cannot load words or file is empty.\n";
        cout << "Provide ./words.txt with one English word per line.\n";
        return 1;
    }

   srand(static_cast<unsigned>(time(nullptr)));
    int idx = rand() % words.size();
    MyString* secret = words.getAt(idx);
    if (!secret){
        cout << "Unexpected error selecting a word."<<endl;
        return 2;
    }

    constexpr int MAX_WRONG = 6;
    int wrong = 0;
    CharSet guesses;

    cout << "Game started! Guess letters (a-z). You have " << MAX_WRONG << " wrong attempts."<<endl;

    while (true){
        drawHangman(wrong);
        cout << "Word: ";
        secret->printMasked(guesses);
        cout << endl;
        cout << "Guessed: ";
        guesses.printSortedLike();
        cout << endl;
        cout << "Wrong: " << wrong << "/" << MAX_WRONG << "";
        cout << endl;

        if (secret->allRevealed(guesses)){
            cout << "You WON! The word was: ";
            secret->printWord();
            cout << endl;
            break;
        }
        if (wrong >= MAX_WRONG){
            cout << "You LOST! The word was: ";
            secret->printWord();
            cout << endl;
            break;
        }

        cout << "Enter a letter: ";
        char ch;
        if (!(cin >> ch)){
            cout << "Input error."<<endl;
            return 3;
        }
        if (!isLetter(ch)){
            cout << "Please enter a letter [a-z]."<<endl;
            continue;
        }
        ch = toLowerChar(ch);
        if (guesses.contains(ch)){
            cout << "Already guessed '" << ch << "'. Try another."<<endl;
            continue;
        }
        guesses.add(ch);
        if (!secret->containsChar(ch)){
            ++wrong;
            cout << "Nope! '" << ch << "' is not in the word."<<endl;
        } else {
            cout << "Nice! '" << ch << "' is in the word."<<endl;
        }
    }

    cout << "Thanks for playing!"<<endl;
    return 0;
}
