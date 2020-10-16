#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user) {
    CMarkup xml;
    if(xml.Load(NAME_FILE) == false) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    } else {
        if (xml.FindElem("Users")) {
        } else
            xml.AddElem("Users");
    }
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("userId", user.getUserId());
    xml.AddElem("login", user.getLogin());
    xml.AddElem("password", user.getPassword());
    xml.AddElem("name", user.getName());
    xml.AddElem("surname", user.getSurname());
    xml.Save(NAME_FILE);
}

vector <User> FileWithUsers::loadUserFromFile() {
    User user;
    vector <User> users;
    CMarkup xml;

    if(xml.Load(NAME_FILE) == true) {
        xml.FindElem("Users");
        xml.IntoElem();
        while (xml.FindElem("User")) {
            xml.IntoElem();
            xml.FindElem();
            user.setUserId(atoi( MCD_2PCSZ(xml.GetData())));
            xml.FindElem();
            user.setLogin(xml.GetData());
            xml.FindElem();
            user.setPassword(xml.GetData());
            xml.FindElem();
            user.setName(xml.GetData());
            xml.FindElem();
            user.setSurname(xml.GetData());
            users.push_back(user);
            xml.OutOfElem();
        }
    }
    return users;
}
