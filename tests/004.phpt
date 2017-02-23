--TEST--
Increment the counter, clear and output it.
--SKIPIF--
<?php if (!extension_loaded("counter")) print "skip"; ?>
--FILE--
<?php
\Counter\bump();
\Counter\clear();
echo \Counter\get();
?>
--EXPECT--
0
