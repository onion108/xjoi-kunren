
fun isPrime(a: Int): Boolean {
    if (a == 1) {
        return false
    }
    if (a == 3 || a == 2 || a == 5) {
        return true
    }
    for (i in 2..(a-1)) {
        if (a % i == 0) {
            return false
        }
    }
    return true
}

var result = "{"

for (i in 1..10000) {
    if (isPrime(i)) {
        result += "true,"
    } else {
        result += "false,"
    }
}

result += "}"
result
