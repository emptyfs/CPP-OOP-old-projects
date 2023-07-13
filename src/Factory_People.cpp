#include "Factory_People.h"

Element* Factory_People::createElement()
{
    return new People;
}
