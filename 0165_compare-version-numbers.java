public class Solution {
    private int[] f1(String s) {
        String[] ss = s.split("\\.");
        int[] ii = new int[ss.length];
        for (int i = 0; i < ii.length; i++) {
            ii[i] = Integer.parseInt(ss[i]);
        }
        return ii;
    }
    private int[] f2(int[] v, int len) {
        int[] ii = new int[len];
        for (int i = 0; i < v.length; i++)
            ii[i] = v[i];
        return ii;
    }
    
    public int compareVersion(String version1, String version2) {
        int[] v1 = f1(version1);
        int[] v2 = f1(version2);
        int maxLen = Math.max(v1.length, v2.length);
        v1 = f2(v1, maxLen);
        v2 = f2(v2, maxLen);
        for (int i = 0; i < maxLen; i++) {
            if (v1[i] < v2[i])      return -1;
            else if (v1[i] > v2[i]) return 1;
        }
        return 0;
    }
}