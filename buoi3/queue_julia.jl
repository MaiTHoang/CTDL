mutable struct Queue
    elements::Vector{Any} #Vector chua cac phan tu

    `new`
    Queue() = new(Vector{Any}())
end

#ham them phan tu vao hang doi
function enqueue!(q::Queue, item)
    push!(q.elements, item) 
    println("Da them '$item' vao hang doi.")
end

#Ham loai bo phan tuu khoi hang doi
function dequeue!(q::Queue)
    if !isempty(q.elements)
        item = popfirst!(q.elements)
        println("Da lay '$item' ra khoi hang doi.")
        return item
    else
        println("Hang doi trong!")
        return nothing
    end
end

#Ham xem phan tu o dau hang doi
function front(q::Queue)
    if !isempty(q.elements)
        return q.elements[1]
    else
        println("Hang doi trong!")
        return nothing
    end
end

#Ham kiemn tra hang doi rong
function is_empty(q::Queue)
    return isempty(q.elements)
end

#Ham in noi dung hang doi
function display(q::Queue)
    println("Hang doi (dau den cuoi): ", q.elements)
end

#Minh hoa su dung hang doi
function main()
    queue = Queue()
    enqueue!(queue, "Tai lieu 1")
    enqueue!(queue, "Tai lieu 2")
    enqueue!(queue, "Tai lieu 3")
    display(queue) #Output: Hang doi (dau den cuoi): ["Tai lieu 1", "Tai lieu 2", "Tai lieu 3"]

    front_item = front(queue)
    println("Phan tu dau cua hang doi: ", front_item) #Output: Phan tu dau cua hang doi: Tai lieu 1

    dequeue!(queue)
    display(queue) #Output: Hang doi (dau den cuoi): ["Tai lieu 2", "Tai lieu 3"]

    println("Hang doi co trong khong? ", is_empty(queue) ? "Co" : "Khong") #Output: Hang doi co trong khong? Khong
end

main()