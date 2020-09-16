#ifndef _13_34_36_37_H_
#define _13_34_36_37_H_

#include <iostream>
#include <set>
#include <string>

using std::string; using std::set; using std::cout; using std::cin; using std::endl;

class Folder;
class Message {
friend class Folder;
friend void swap(Message&, Message&);
public:
    explicit Message(const string &str=""): contents(str) {}
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();

    void save(Folder&);
    void remove(Folder&);
private:
    string contents;
    set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();
    void addFldr(Folder *);
    void remFldr(Folder *);
};

class Folder {
friend class Message;
friend void swap(Message&, Message&);
public:
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();
private:
    set<Message*> messages;
    void addMsg(Message*);
    void remMsg(Message*);
    void add_to_Messages(const Folder&);
    void remove_from_Msgs();
};

#endif