class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        folder.sort()
        ans = [folder[0]]

        for i in range(1, len(folder)):
            curr_folder = folder[i]
            last_folder = ans[-1] + "/"

            if not curr_folder.startswith(last_folder):
                ans.append(curr_folder)

        return ans






# class Solution:
#     def removeSubfolders(self, folder: List[str]) -> List[str]:
#         folder_set = set(folder)
#         ans = []

#         for path in folder:
#             is_subfolder = False
#             current_path = path

#             while current_path:
#                 position = current_path.rfind('/')
#                 current_path = current_path[:position]

#                 if current_path in folder_set:
#                     is_subfolder = True
#                     break

#             if not is_subfolder:
#                 ans.append(path)

#         return ans