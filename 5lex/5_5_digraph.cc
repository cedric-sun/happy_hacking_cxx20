// cesun, 5/15/20 12:33 AM.

%:include <cstdio>

int main() <%
    unsigned x = 0xabcdefu bitand 0x123456u;
    x xor_eq 0x8195u;
    unsigned y = compl 0x19f9au;
    if (x and y) <%
        std::printf("%d\n",<::><% return 42; }());
    %>
%>
