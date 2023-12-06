#pragma once

#include <iostream>
#include <exception>
#include <algorithm>

#include <string>
#include <iostream>

class Seven
{ 
public:
   Seven();
   Seven(const std::string& t);
   Seven(const std::initializer_list< unsigned char> &t);
   Seven(const Seven& other);
   Seven(Seven&& other) noexcept;      
   Seven operator + (const Seven& other) const;
   Seven operator - (const Seven& other) const;
   bool operator == (const Seven& other) const;
   bool operator != (const Seven& other) const;
   bool operator < (const Seven& other) const;
   bool operator > (const Seven& other) const;
   bool operator <= (const Seven& other) const;
   bool operator >= (const Seven& other) const;
   Seven &operator = (const Seven& other);
   std::ostream&   print(std::ostream& os);

   virtual ~Seven() noexcept;
private:
    size_t _size;
    unsigned char *_number;
};