import QtQuick 2.0
import QtTest 1.0
import Testable 1.0
import Shell 1.0

TestCase {
    name: "QmlShell"

    function test_cat() {
        var input = Qt.resolvedUrl("../testdata/dummy1.txt");
        var content = Shell.cat(input);
        compare(content, "dummy1.txt\ncontent\n");
    }

    function test_find() {
        var input = Qt.resolvedUrl("../testdata/").replace("file://", "");
        var files = Shell.find(input, "*.txt");

        compare(files.length, 1);
    }

    function test_realpath_strip() {

        compare(Shell.realpath_strip(":tmp"),  ":tmp");
        compare(Shell.realpath_strip(":/tmp"), ":/tmp");

        compare(Shell.realpath_strip("tmp","/subdir1/","subdir2"),  Shell.pwd() + "/tmp/subdir1/subdir2");

    }

    function test_dirname() {
        compare(Shell.dirname("/tmp"),  "/");
    }

    function test_basename() {
        compare(Shell.basename("/tmp/123.txt"),  "123.txt");
    }

}
