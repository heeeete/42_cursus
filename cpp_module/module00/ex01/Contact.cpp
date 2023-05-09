#include "./Contact.hpp"

Contact::~Contact() {}

void	Contact::set_first_name(const std::string str) { _first_name = str; }

void	Contact::set_last_name(const std::string str) { _last_name = str; }

void	Contact::set_nick_name(const std::string str) { _nick_name = str; }

void	Contact::set_phone_number(const std::string str) { _phone_number = str; }

void	Contact::set_darkest_secret(const std::string str) { _darkest_secret = str; }

std::string	Contact::get_first_name() const  { return _first_name; }

std::string	Contact::get_last_name() const  { return _last_name; }

std::string	Contact::get_nick_name() const  { return _nick_name; }

std::string	Contact::get_phone_number() const  { return _phone_number; }

std::string	Contact::get_darkest_secret() const  { return _darkest_secret; }
