class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        folder_set = set(folder)
        ans = []

        for path in folder:
            is_subfolder = False
            current_path = path

            while current_path:
                position = current_path.rfind('/')
                current_path = current_path[:position]

                if current_path in folder_set:
                    is_subfolder = True
                    break

            if not is_subfolder:
                ans.append(path)

        return ans