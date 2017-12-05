#include "Model.h"

bool Model::operator==(Model* m)
{
	if (item->operator==(m->getItem()))
		return true;

	return false;
}
