import QtQuick 2.0
import QtTest 1.0
import Testable 1.0
import Shell 1.0

TestCase {
    name: "QmlShell"

    function test_cat() {
        var input = Qt.resolvedUrl("../testdata/dummy1.txt").replace("file://", "");
        var content = Shell.cat(input);
        compare(content, "dummy1.txt\ncontent\n");
    }

    function test_find() {
        var input = Qt.resolvedUrl("../testdata/").replace("file://", "");

        console.log(input);
        var files = Shell.find(input, "*.txt");

        compare(files.length, 1);
    }
}
