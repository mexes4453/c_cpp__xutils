#ifndef XUTILS_HPP
# define XUTILS_HPP

# include <cstdlib>
# include <unistd.h>

# define XUTILS__COL_BLUE               "\033[0;34m"
# define XUTILS__COL_GREEN              "\033[0;32m"
# define XUTILS__COL_RED                "\033[0;31m"
# define XUTILS__COL_DEFAULT            "\033[0m"

/* Format the error msg with red color */
# define XUTILS__ERR_MSG_FMT(msg) \
         XUTILS__COL_RED msg XUTILS__COL_DEFAULT  /* format the err msg */

/* Format the msg with color */
# define XUTILS__FMT_MSG(color,msg) \
         color msg XUTILS__COL_DEFAULT  



namespace xutils
{
    enum enPtrCreateMethod
    {
        enPtrCreateMethod_Malloc = 0,
        enPtrCreateMethod_New,
    };

    template <typename T>
    void freePtr(T *pT, enum enPtrCreateMethod m)
    {
        if (pT)
        {
            if (m == enPtrCreateMethod_Malloc)
            {
                free( pT );
                pT = NULL;
            }
            else if(m == enPtrCreateMethod_New)
            {
                delete pT;
                pT = nullptr;
            }
        }
    }
}


# endif /* XUTILS */