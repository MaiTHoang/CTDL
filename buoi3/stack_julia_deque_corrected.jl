#stack_julia_deque_corrected.jl
using DataStructures

struct Stack
    elements::Deque{Any} #Su dung Deque de luu tru phan tu
    Stack() = Stack(Deque{Any}()) #Constructor khoi tao ngan xep rong
end

#Ham them phan tu vao ngan xep
function push!(s::Stack, item)
    enqueue!(s.elements, item) #Them vao cuoi Deque
    println("Da them '$item' vao ngan xep.")
end

#Ham loai bo phan tu khoi ngan xep
function pop!(s::Stack)
    if !isempty(s.elements)
        item = popback!(s.elements) #Loai bo phan tu cuoi cua Deque 
        println("Da lay '$item' ra khoi ngan xep.")
        return item
    else
        println("Ngan xep trong!")
        return nothing
    end
end

#Ham xem phan tu o dinh ngan xep
function peek(s::Stack)
    if !isempty(s.elements)
        return last(s.elements) #Lay phan tu cuoi cung
    else
        println("Ngan xep trong!")
        return nothing
    end
end

#Ham kiem tra ngan xep rong
function is_empty(s::Stack)
    return isempty(s.elements)
end

#ham in noi dung ngan xep
function display(s::Stack)
    println("Ngan xep (dinh den day): ")
    collect(reverse(s.elements))
end

#Minh hoa su dung ngan xep voi Deque
function main()
    stack = Stack()
    push!(stack, "Sach A")
    push!(stack, "Sach B")
    push!(stack, "Sach C")
    display(stack) #Output: Ngan xep (dinh den day) ["Sach C", "Sach B", "Sach A"]

    top_item = peek(stack)
    println("Phan tu dinh cua ngan xep: ", top_item) #Output: Phan tu dinh cua ngan xep: Sach C

    pop!(stack)
    display(stack) #Output: Ngan xep (dinh den day) ["Sach B", "Sach A"]

    println("Ngan xep co trong khong? ", is_empty(stack) ? "Co" : "Khong") #Output: Ngan xep co trong khong? Khong
end

main()