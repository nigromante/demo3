#ifndef FILE_HPP_
#define FILE_HPP_

#include <string>

namespace Nigromante
{

    class File
    {
    public:
        std::string ReadFile(const std::string &filename) const;
    };

} // #end of File

#endif // FILE_HPP_