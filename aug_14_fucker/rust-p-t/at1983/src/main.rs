use std::io::stdin;

static g_mod: i64 = (1e9 as i64)+7;

fn read_one() -> i64 {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().parse::<i64>().unwrap()
}

fn read_two() -> (i64, i64) {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    let sd = s.trim().split(' ').map(|x| x.parse::<i64>().unwrap()).collect::<Vec<i64>>();
    (sd[0], sd[1])
}

fn fast_pow(mut a: i64, mut b: i64) -> i64 {
    let mut ans = 1;
    while b != 0 {
        if (b & 1) != 0 {
            ans = (ans * a) % g_mod;
        }
        b >>= 1;
        a = (a*a) % g_mod;
    }
    ans
}

fn init(dp: &mut [[i64; 4010]; 4010], fac: &mut [i64; 8010], inv: &mut [i64; 8010]) {
    for i in 1..=4004 {
        for j in 1..=4004 {
            dp[i][j] = ((dp[i][j] + dp[i-1][j]) % g_mod + dp[i][j-1]) % g_mod;
        }
    }
    fac[0] = 1;
    inv[0] = 1;
    for i in 1..=8004 {
        fac[i] = (fac[i-1]*(i as i64)) % g_mod;
        inv[i] = fast_pow(fac[i], g_mod - 2);
    }
}

fn calc_c(fac: &mut [i64; 8010], inv: &mut [i64; 8010], n: i64, m: i64) -> i64 {
    (fac[n as usize] * inv[(n-m) as usize]) % g_mod * inv[m as usize] % g_mod
}

fn main() {
    let mut dp: [[i64; 4010]; 4010] = [[0; 4010]; 4010];
    let mut a: [i64; 200005] = [0; 200005];
    let mut b: [i64; 200005] = [0; 200005];
    let mut fac: [i64; 8010] = [0; 8010];
    let mut inv: [i64; 8010] = [0; 8010];
    let n = read_one();
    for i in 1..=n {
        let ip = read_two();
        a[i as usize] = ip.0;
        b[i as usize] = ip.1;
        dp[2001-a[i as usize] as usize][2001-b[i as usize] as usize] += 1;
    }
    init(&mut dp, &mut fac, &mut inv);
    let mut sum = 0_i64;
    for i in 1..=n {
        sum = (sum+dp[2001+a[i as usize] as usize][2001+b[i as usize] as usize]) % g_mod;
        sum = (sum - calc_c(&mut fac, &mut inv, a[i as usize]+a[i as usize]+b[i as usize]+b[i as usize], a[i as usize]+a[i as usize]) + g_mod) % g_mod;
    }
    sum = (sum * 500000004) % g_mod;
    println!("{}", sum);
}
