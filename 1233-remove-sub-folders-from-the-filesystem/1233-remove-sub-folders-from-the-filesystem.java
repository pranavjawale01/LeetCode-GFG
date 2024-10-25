class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Arrays.sort(folder);
        List<String> ans = new ArrayList<>();
        ans.add(folder[0]);

        for (int i = 1; i < folder.length; i++) {
            String currFolder = folder[i];
            String lastFolder = ans.get(ans.size() - 1) + "/";

            if (!currFolder.startsWith(lastFolder)) {
                ans.add(currFolder);
            }
        }

        return ans;
    }
}











// class Solution {
//     public List<String> removeSubfolders(String[] folder) {
//         Set<String> set = new HashSet<>(Arrays.asList(folder));
//         List<String> ans = new ArrayList<>();

//         for (String path : folder) {
//             boolean isSubFolder = false;
//             String currentPath = path;

//             while (!currentPath.isEmpty()) {
//                 int position = currentPath.lastIndexOf('/');
//                 currentPath = currentPath.substring(0, position);

//                 if (set.contains(currentPath)) {
//                     isSubFolder = true;
//                     break;
//                 }
//             }

//             if (!isSubFolder) {
//                 ans.add(path);
//             }
//         }

//         return ans;
//     }
// }