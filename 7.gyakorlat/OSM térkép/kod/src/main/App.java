package OSMTerkep.mivan;

import java.util.*;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;

import javax.swing.JFrame;

import org.jxmapviewer.JXMapViewer;
import org.jxmapviewer.OSMTileFactoryInfo;
import org.jxmapviewer.painter.CompoundPainter;
import org.jxmapviewer.painter.Painter;
import org.jxmapviewer.viewer.DefaultTileFactory;
import org.jxmapviewer.viewer.DefaultWaypoint;
import org.jxmapviewer.viewer.GeoPosition;
import org.jxmapviewer.viewer.TileFactoryInfo;
import org.jxmapviewer.viewer.Waypoint;
import org.jxmapviewer.viewer.WaypointPainter;

public class App implements MouseWheelListener
{
    public static void main(String[] args)
    {
        final JXMapViewer mapViewer = new JXMapViewer();

        mapViewer.addMouseWheelListener(new MouseWheelListener() {
        	public void mouseWheelMoved(MouseWheelEvent e) {
        		mapViewer.setZoom(mapViewer.getZoom() + e.getWheelRotation());
        	};
        });
        
        //Megjelenítõ ablak
        JFrame frame = new JFrame("Debreceni Egyetem - Campusok");
        frame.getContentPane().add(mapViewer);
        frame.setSize(800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setExtendedState(JFrame.MAXIMIZED_BOTH); 
        frame.setVisible(true);

        //OSM térkép lekérdezéséhez
        TileFactoryInfo info = new OSMTileFactoryInfo();
        DefaultTileFactory tileFactory = new DefaultTileFactory(info);
        mapViewer.setTileFactory(tileFactory);
        
        //Elemek listához adása
        List<GeoPosition> track = new ArrayList<GeoPosition>();
        track.add(new GeoPosition(47.5432758,21.640377700000045));
        track.add(new GeoPosition(47.5491491,21.60869600000001));
        track.add(new GeoPosition(47.5535039,21.62147559999994));
        
        //Ez a megjelenítéshez
        List<DefaultWaypoint> waypoint = new ArrayList<DefaultWaypoint>();
        for(GeoPosition p : track)
        	waypoint.add(new DefaultWaypoint(p));
        Set<Waypoint> waypoints = new HashSet<Waypoint>(waypoint);

        //Fókuszálás beállítása
        mapViewer.zoomToBestFit(new HashSet<GeoPosition>(track), 0.7);

        //Waypoint painter
        WaypointPainter<Waypoint> waypointPainter = new WaypointPainter<Waypoint>();
        waypointPainter.setWaypoints(waypoints);

        //Compound painter
        List<Painter<JXMapViewer>> painters = new ArrayList<Painter<JXMapViewer>>();
        painters.add(waypointPainter);

        CompoundPainter<JXMapViewer> painter = new CompoundPainter<JXMapViewer>(painters);
        mapViewer.setOverlayPainter(painter);
    }
}