extern void __real_foo();
extern void __real_bar();

void __wrap_foo(void)
{
  __real_foo();
}

void __wrap_bar(void)
{
  __real_bar();
}
