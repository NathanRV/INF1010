/********************************************
* Titre: Travail pratique #6 - ExceptionArgumentInvalide.h
* Date: 28 novembre 2019
* Auteur: Nathan RAMSAY-VEJLENS
*******************************************/

#ifndef EXCEPTIONARGUMENTINVALIDE_H
#define EXCEPTIONARGUMENTINVALIDE_H

#include <QException>
#include <QString>

class ExceptionArgumentInvalide : public QException {
public:

    //Constructeur par parametres
    ExceptionArgumentInvalide(QString s)
        : s_(s)
    {}

    //Surcharge fonction what() afin de retourner attribut s
    const char* what() const noexcept
    {
        return s_.toUtf8();
    }
private:
    QString s_;
};
#endif // EXCEPTIONARGUMENTINVALIDE_H
