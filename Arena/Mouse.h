#ifndef MOUSE_H_
#define MOUSE_H_

// ---------------------------------------------------------------------------------

#include "Object.h"        
#include "Types.h"        

// ---------------------------------------------------------------------------------

class Mouse : public Object
{
public:
    Mouse();//Construtor
    ~Mouse();//Destrutor

    bool Clicked();
    bool Over(Object* obj);
    void Update();
    void Draw();
};

// ---------------------------------------------------------------------------------

#endif
