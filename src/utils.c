#include "malloc.h"

type alloc_type(size_t size) {
	if (size <= TINY_ALLOC) {
		return (TINY);
	} else if (size <= SMALL_ALLOC) {
		return (SMALL);
	} else {
		return (LARGE);
	}
}

size_t alloc_size(type __type) {
	if (__type == TINY) {
		return (TINY_ZONE);
	} else {
		return (SMALL_ZONE);
	}
}
