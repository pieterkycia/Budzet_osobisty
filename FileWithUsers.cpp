#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user) {
    CMarkup xml;
    if(xml.Load(NAME_FILE) == false) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("User");
    } else {
        if (xml.FindElem("User")) {
        } else
            xml.AddElem("User");
    }
    xml.IntoElem();
    xml.AddElem("Users");
    xml.IntoElem();
    xml.AddElem("userId", user.getUserId());
    xml.AddElem("login", user.getLogin());
    xml.AddElem("password", user.getPassword());
    xml.AddElem("name", user.getName());
    xml.AddElem("surname", user.getSurname());
    xml.Save(NAME_FILE);
}
