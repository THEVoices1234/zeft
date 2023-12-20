//
// Created by Adam on 12/5/2023.
//

#ifndef UNTITLED_OBJECT_H
#define UNTITLED_OBJECT_H
class Object {
protected:
    char type;
public:
    Object(char t);

    char getType() const;
    void setType(const char&&t);
    virtual ~Object();

    Object();
};
#endif //UNTITLED_OBJECT_H
