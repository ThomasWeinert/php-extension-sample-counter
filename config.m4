PHP_ARG_ENABLE(counter,
  [Whether to enable the "counter" extension],
  [  --enable-counter        Enable "counter" extension support])

if test $PHP_COUNTER != "no"; then
  PHP_SUBST(COUNTER_SHARED_LIBADD)
  PHP_NEW_EXTENSION(counter, counter.c, $ext_shared)
fi