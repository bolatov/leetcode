class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        st = set()
        for e in emails:
            local, domain = e.split('@')
            plus_pos = local.find('+')
            if plus_pos >= 0:
                local = local[:plus_pos]
            email = local.replace('.', '') + '@' + domain
            st.add(email)
        return len(st)
