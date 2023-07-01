//https://www.codingninjas.com/studio/problems/find-nth-root-of-m_8230799?challengeSlug=striver-sde-challenge&leftPanelTab=1

int NthRoot(int n, int m) {
    if (m < 0 && n % 2 == 0) {
        // Invalid input: negative number with even root
        return -1;
    }

    long long low = 0;
    long long high = m;
    long long ans = -1;

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long result = 1;
        
        for (int i = 1; i <= n; i++) {
            result *= mid;
            
            if (result > m) {
                break;
            }
        }
        
        if (result == m) {
            ans = mid;
            break;
        } else if (result < m) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return static_cast<int>(ans);
}
