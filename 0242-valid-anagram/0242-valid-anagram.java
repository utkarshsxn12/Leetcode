class Solution {
    static HashMap<Character, Integer> HashMapFreq (String str){
        HashMap<Character, Integer> mp = new HashMap <>();
        for(int i=0; i<str.length(); i++){
            Character ch = str.charAt(i);
            if(!mp.containsKey(ch)){
                mp.put(ch, 1);
            }
            else{
                int currFre = mp.get(ch);
                mp.put(ch, currFre+1);
            }
        }
        return mp;
    }
    public boolean isAnagram(String s, String t) {
        if(s.length()!=t.length()) return false;
        HashMap<Character, Integer> mp1 = HashMapFreq(s);
        HashMap<Character, Integer> mp2 = HashMapFreq(t);
        return mp1.equals(mp2);
    }
}