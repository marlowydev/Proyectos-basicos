#include "ArdillasSkin.h"

namespace Skins {

    std::string Ardilla_Noob(std::string nombre) {
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

    std::string Ardilla_Pro(std::string nombre) {
        std::string dibujo = R"(    
      {` '`-.
      {       \    (/\._
      {       | /   [■-■].
       `}    /. , '___.'
      {  /_   '-. \_/`\
       {  ,` PRO  \='
      {  ;       /_
       `'--'...-;__\

        )";
        
        return dibujo;
    }
    std::string Ardilla_Noob_nemigo(std::string nombre) {
        std::string dibujo = R"(
                  .-'` `}
          _./)   /       }
        .'o   \ |       }
        '.___.'`.\    {`
        /`\_/  , `.    }
        \=' .-'   _`\  {
         `'`;/      `,  }
            _\       ;  }
        /__`;-...'--'
          
        )";
        
        return dibujo;
    }

    std::string Ardilla_Pro_nemigo(std::string nombre) {
        std::string dibujo = R"(
                    .-'` `}
          _./)   /       }
        .'[■-■]\ |       }
        '.___.'`.\    {`
        /`\_/  , `.    }
         \=' .-'   _`\  {
        `'`;/      `,  }
         _\       ;  }
        /__`;-...'--'

        )";
        
        return dibujo;



    }
}