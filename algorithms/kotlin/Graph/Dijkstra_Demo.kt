package com.mahbub.algorithm.graph

import java.io.FileInputStream
import java.io.FileNotFoundException
import java.util.*

class Dijkstra_Demo {

    class Node : Comparable<Node> {
        var label = 0
        var dist = 0

        constructor(label: Int, dist: Int) {
            this.label = label
            this.dist = dist
        }

        override fun compareTo(o: Node): Int {
            return (this.dist - o.dist)
        }
    }

    var NODES : Int = 0
    var EDGES : Int = 0
    var G : Array<MutableList<Node>> = arrayOf()
    var source : Int = 0

    var dist : IntArray = IntArray(0)
    var parent : IntArray = IntArray(0)
    var pq : PriorityQueue<Node> = PriorityQueue()

    fun dijkstra() {
        dist = IntArray(NODES+1) { Int.MAX_VALUE }
        parent = IntArray(NODES+1) { -1 }

        var u : Node
        var v : Node

        pq = PriorityQueue()
        dist[source] = 0
        u = Node(source, 0)
        pq.offer(u)

        while(!pq.isEmpty()) {
            u = pq.poll()

            for (i in 0 until G[u.label].size) {
                var p = G[u.label][i]
                v = Node(p.label, 0)

                if (dist[u.label] + p.dist < dist[p.label]) {
                    dist[p.label] = dist[u.label] + p.dist
                    v.dist = dist[u.label] + p.dist;
                    parent[v.label] = u.label;
                    pq.offer(v);
                }
            }
        }
    }

    fun printDist() {
        println("Dist: ")
        for (i in 1 until dist.size) print("${dist[i]} ")
        println()
    }

    fun printParent() {
        println("Parent ")
        for (i in 1 until parent.size) print("${parent[i]} ")
        println()
    }

    fun fakeMain() {
        var scanner = inputFromFile()

        NODES = scanner!!.nextInt()
        EDGES = scanner!!.nextInt()

        G = Array(NODES+1) { ArrayList<Node>() }
        for (i in 0 until EDGES) {
            var u = scanner!!.nextInt()
            var v = scanner!!.nextInt()
            var c = scanner!!.nextInt()

            G[u].add(Node(v, c))
            G[v].add(Node(u, c))
        }

        source = scanner!!.nextInt()

        dijkstra();

        printDist();
        printParent();
    }
}

fun main(args : Array<String>) {
    Dijkstra_Demo().fakeMain()
}

private fun inputFromFile() : Scanner? {
    return try { Scanner(FileInputStream("input.txt")) }
    catch (e : FileNotFoundException) { null }
}

private fun inputFromSystem() : Scanner? {
    return Scanner(System.`in`)
}
