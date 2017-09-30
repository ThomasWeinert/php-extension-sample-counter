--TEST--
Increment the counter once and output it.
--SKIPIF--
<?php if (!extension_loaded("counter")) print "skip"; ?>
--FILE--
<?php
$counter = \Counter\counter_create('sample');
Counter\counter_bump_value($counter);
echo \Counter\counter_get_value($counter);
?>
--EXPECT--
1
