--TEST--
Increment the counter once and output it.
--SKIPIF--
<?php if (!extension_loaded("counter")) print "skip"; ?>
--FILE--
<?php
\Counter\bump();
echo \Counter\get();
?>
--EXPECT--
1
