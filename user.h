#ifndef USER_H
#define USER_H
#include <QString>
#include <QDate>

class User
{
private:
    QString username;
    QString password;
    QString email;
    QDate birthday;
    int winGames;
    double userRating;
public:
    User();
    User(const QString& username, const QString& email, const QString& password, const QDate& birthday_);

    User(const User& other);

    const QString get_username() const;

    const QString get_password() const;

    const QString get_email() const;

    const QDate get_birthday() const;

    int get_winGames() const;

    double get_userRating() const;

    void set_username(const QString& username_);

    void set_password(const QString& password_);

    void set_email(const QString& email_);

    void set_birthday(const QDate& birthday_);

    void set_winGames(const int winGames_);

    void set_userRating(const double userRating_);

    User& operator++();

    User operator++(int);

    User& operator--();

    User operator--(int);

    User& operator+(double addRating);
    User& operator-(double decreaseRating);

    User& operator=(const User& other);
};

#endif // USER_H
