#include <cassert>

const int _MAX_MEM = 1e8;
int _allocator_pos = 0;
char _allocator_memory[_MAX_MEM];
inline void *operator new(size_t n) {
  char *res = _allocator_memory + _allocator_pos;
  _allocator_pos += n;
  assert(_allocator_pos <= _MAX_MEM);
  return (void *)res;
}
inline void operator delete(void *) {}