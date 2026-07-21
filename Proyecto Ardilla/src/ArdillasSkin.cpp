#include "ardillasSkin.h"

namespace Skins {

    std::string Ardilla_Noob() {
        // Usamos R"( ... )" para el literal de cadena sin formato
        std::string dibujo = R"(
      {` '`-.
      {       \   (/._
      {       | \   o'.
       `}    /. , '___.'
      {  /_   '-. \_/`\
       {  ,`      \='
      {  ;       /_
       `'--'...-;__\

        )";
        
        return dibujo;
    }

    std::string Ardilla_Pro() {
        std::string dibujo = R"(    
      {` '`-.
      {       \    (/\._
      {         | /[■-■].
       `}    /. , '___.'
      {  /_   '-. \_/`\
       {  ,` PRO  \='
      {  ;       /_
       `'--'...-;__\

        )";
        
        return dibujo;
    }
    std::string Ardilla_Noob_enemigo() {
        std::string dibujo = R"(
                  .-'` `}
          _./)   /       }
        .'o   \ |       }
        '.___.'`.\    {`
        /`\_/  , `.    }
        \=' .-'   _`\  {
         `'`;/      `,  }
            _\       ;  }
        /__`;-...'--.

        )";
        
        return dibujo;
    }

    std::string Ardilla_Pro_enemigo() {
        std::string dibujo = R"(
                    .-'` `}
          _./)   /       }
        .'[■-■]\ |       }
        '.___.'`.\    {`
        /`\_/  , `.    }
         \=' .-'   _`\  {
        `'`;/      `,  }
         _\        }
        /__`;-...'-

        )";
        
        return dibujo;



    }
}