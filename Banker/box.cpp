#include "box.h"

Box::Box()
{

}
void Box::clearProcess()
{
    for (int i = 0; i<pLength; i++)
            {
                p[i].currentAvail.SetSource(0, 0, 0);
            }

}

