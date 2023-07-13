#include "Factory_Medicine.h"

Element* Factory_Medicine::createElement()
{
    return new Medicine;
}
