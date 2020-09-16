#include <iostream>
#include <string>
#include <set>

#include "13-34-36-37.h"

using namespace std;

Message::Message(const Message &m): contents(m.contents), folders(m.folders) {
    add_to_Folders(m);
}

Message& Message::operator=(const Message &rhs) {
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

Message::~Message() {
    remove_from_Folders();
}

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

// Add this Message to Folders that point to m
void Message::add_to_Folders(const Message &m) {
    for(auto f : m.folders) {
        f->addMsg(this);
    }
}

void Message::remove_from_Folders() {
    for(auto f : folders) {
        f->remMsg(this);
    }
}

void Message::addFldr(Folder *f) {
    folders.insert(f);
}

void Message::remFldr(Folder *f) {
    folders.erase(f);
}

void swap(Message &lhs, Message &rhs) {
    using std::swap;
    for(auto f : lhs.folders) {
        f->remMsg(&lhs);
    }
    for(auto f : rhs.folders) {
        f->remMsg(&rhs);
    }
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for(auto f : lhs.folders) {
        f->addMsg(&lhs);
    }
    for(auto f : rhs.folders) {
        f->addMsg(&rhs);
    }
}


Folder::Folder(const Folder &f) {
    add_to_Messages(f);
}

Folder& Folder::operator=(const Folder &f) {
    remove_from_Msgs();
    messages = f.messages;
    add_to_Messages(f);
    return *this;
}

Folder::~Folder() {
    remove_from_Msgs();
}

void Folder::addMsg(Message *msg) {
    messages.insert(msg);
}

void Folder::remMsg(Message *msg) {
    messages.erase(msg);
}

void Folder::add_to_Messages(const Folder &f) {
    for(auto msg : f.messages) {
        msg->addFldr(this);
    }
}

void Folder::remove_from_Msgs() {
    while(!messages.empty()) {
        (*messages.begin())->remove(*this);
    }
}