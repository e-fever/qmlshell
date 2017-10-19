pragma Singleton
import QtQuick 2.0
import Shell.Private 1.0

QtObject {

    function pwd() {
        return ShellAdapter.pwd();
    }

    function cat(file) {
        return ShellAdapter.cat(file);
    }

    function find(path, filters) {
        return ShellAdapter.find(arguments);
    }

    function realpath_strip() {
        return ShellAdapter.realpath_strip(arguments);
    }
}
