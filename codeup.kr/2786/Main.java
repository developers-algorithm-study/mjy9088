
import java.util.Comparator;
import java.util.LinkedList;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.TreeMap;

public class Main
{
	public static class BuildingInfo
	{
		public int height;
		public boolean end;

		public BuildingInfo(int height, boolean end)
		{
			this.height = height;
			this.end = end;
		}
	}

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);

		// 건물 개수
		int N = sc.nextInt();

		// 모든 건물의 시작점/끝점, 높이 정보 (위치별)
		TreeMap<Integer, LinkedList<BuildingInfo>> buildingInfo = new TreeMap<>();

		// 입력
		for(int i = 0; i < N; i++)
		{
			int x_start = sc.nextInt();
			int x_end = sc.nextInt();
			int height = sc.nextInt();

			// 현재 건물 시작점/끝점 위치의 리스트
			LinkedList<BuildingInfo> tmp;

			// 시작점
			tmp = buildingInfo.get(x_start);
			if (tmp == null)
			{
				tmp = new LinkedList<>();
				buildingInfo.put(x_start, tmp);
			}
			// 추가
			tmp.add(new BuildingInfo(height, false));

			// 끝점
			tmp = buildingInfo.get(x_end);
			if (tmp == null)
			{
				tmp = new LinkedList<>();
				buildingInfo.put(x_end, tmp);
			}
			// 추가
			tmp.add(new BuildingInfo(height, true));
		}

		// 현재 재원이의 발 밑에 있는 건물 정보 <위치, 개수>
		TreeMap<Integer, Integer> currentBuildings = new TreeMap<>();

		// 위치
		int previousX = 0;
		// 높이
		int previousHeight = 0;
		// 누적 거리
		long distance = 0;

		while(true)
		{
			// 이전 위치 다음의 건물 시작점/끝점
			Integer currentX = buildingInfo.ceilingKey(previousX + 1);

			// 더 건물이 없으면 끝
			if(currentX == null) break;

			// 현위치의 모든 시작점/끝점을 처리
			for(BuildingInfo info : buildingInfo.get(currentX))
			{
				// 시작점인 경우
				if(!info.end)
				{
					// 발 밑 해당 높이에 건물 추가
					currentBuildings.put(info.height, currentBuildings.getOrDefault(info.height, 0) + 1);
				}
				else
				{
					// 끝점이면 발 밑에 건물 하나 제거하고,
					int buildingCount = currentBuildings.get(info.height) - 1;
					// 남은 건물이 없으면
					if(buildingCount == 0)
					{
						// 가장 높은 키를 통해 현재 높이를 알아내기 위해서 해당 높이의 키를 제거함
						currentBuildings.remove(info.height);
					}
					else
					{
						currentBuildings.put(info.height, buildingCount);
					}
				}
			}

			// 현재 높이
			int currentHeight;
			try
			{
				// 발 밑에 건물이 있으면 그 중 가장 높은 건물
				currentHeight = currentBuildings.lastKey();
			}
			catch(NoSuchElementException e)
			{
				// 발 밑에 건물이 없으면 0
				currentHeight = 0;
			}

			// 추가로 이동한 거리 계산
			int distanceX = currentX - previousX;
			int distanceY = currentHeight - previousHeight;
			if(distanceY < 0)
			{
				distanceY = -distanceY;
			}

			// 누적
			distance += distanceX + distanceY;

			// 현재 위치, 높이 저장
			previousX = currentX;
			previousHeight = currentHeight;
		}

		// 결과
		System.out.println(distance);
	}
}
