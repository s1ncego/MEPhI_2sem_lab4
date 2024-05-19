#pragma once

template<typename T>
T helpFuncMap(T &value) {
    value++;

    return value;
}

template<typename T>
bool helpFuncWhere(T &value) {
    if (value > 2) {
        return true;
    } else {
        return false;
    }
}

