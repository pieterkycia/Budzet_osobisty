#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User & user) {
    CMarkup xml;
    if(xml.Load(FILE_NAME) == false) {
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
    xml.Save(FILE_NAME);
}

vector <User> FileWithUsers::loadUserFromFile() {
    User user;
    vector <User> users;
    CMarkup xml;

    if(xml.Load(FILE_NAME) == true) {
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

void FileWithUsers::changeUserPasswordInFile(User & user) {
    CMarkup xml;

    xml.Load(FILE_NAME);
    xml.FindElem("Users");
    xml.IntoElem();
    while (xml.FindElem("User")) {
        xml.IntoElem();
        xml.FindElem("userId");
        if (atoi( MCD_2PCSZ(xml.GetData())) == user.getUserId()) {
            xml.FindElem("password");
            xml.SetData(user.getPassword());
            xml.Save(FILE_NAME);
            return;
        }
        xml.OutOfElem();
    }
}
